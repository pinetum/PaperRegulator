#include "MainDialog.h"
#include <wx/log.h>
#include <wx/clipbrd.h>
#include <wx/string.h>
#include <wx/utils.h>
#include <wx/uri.h>
wxDEFINE_EVENT(wxEVT_COMMAND_ON_TIMER, wxThreadEvent);
MainDialog::MainDialog(wxWindow* parent)
    : MainDialogBaseClass(parent)
{
	SetSize(750, 600);
	Center();
	transData ="";
    last_transData="";
	SetTitle("PaperRegulator");
	m_timer = new wxTimer(this,-1);
	Bind(wxEVT_TIMER, &MainDialog::OnTimer,this);
	m_timer->Start(300);
	m_b_scanning = true;
}

MainDialog::~MainDialog()
{
	m_timer->Stop();
	delete m_timer;
}
void MainDialog::getClip(){
	
	if (wxTheClipboard->Open())
	{
		if (wxTheClipboard->IsSupported( wxDF_TEXT ))
		{
			wxTextDataObject data;
			wxTheClipboard->GetData( data );
			transData = data.GetText();
			transData.Replace(_("- "), _(""), true);
			transData.Replace(_("\n"), _(""), true);
			m_richTextCtrl22->Clear();
			m_richTextCtrl22->AppendText(transData);
			//transData = paperText;
		}
		wxTheClipboard->Close();
	}
	
}
void MainDialog::OnBtnGOClick(wxCommandEvent& event)
{
	
	getClip();
	
}
void MainDialog::OnContentInserted(wxRichTextEvent& event)
{
    if(last_transData == transData)
        return;
    last_transData = transData;
	wxString str_url = "https://translate.google.com.tw/?oe=UTF-8&ie=UTF-8&hl=zh-TW&client=tw-ob#en/zh-TW/";
	str_url.Append(transData);
	wxURI url (str_url);
	str_url = url.BuildURI();
    m_webView->LoadURL(str_url);
	
	//wxLaunchDefaultBrowser(str_url);
	
	
}
void MainDialog::OnTextUpdate(wxCommandEvent& event)
{
}

void MainDialog::OnTimer(wxTimerEvent& event){
		
	getClip();
}

void MainDialog::OnBtnScanClick(wxCommandEvent& event){
	if(m_b_scanning){
		m_b_scanning = false;
		m_buttonScan->SetLabel(_("Scan:off"));
		m_timer->Stop();
	}
	else
	{
		m_b_scanning = true;
		m_timer->Start(3000);
		m_buttonScan->SetLabel(_("Scan:on"));
	}
	
}
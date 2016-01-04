.PHONY: clean All

All:
	@echo "----------Building project:[ PaperRegulator - Debug ]----------"
	@"$(MAKE)" -f  "PaperRegulator.mk"
clean:
	@echo "----------Cleaning project:[ PaperRegulator - Debug ]----------"
	@"$(MAKE)" -f  "PaperRegulator.mk" clean

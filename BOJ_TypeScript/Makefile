# Makefile for running TypeScript BOJ solutions
# Usage: make <problem_number>
# Example: make 11382

%:
	@echo "Running problem $@..."
	@if [ -f $@.txt ]; then \
		npx ts-node $@_*.ts < $@.txt; \
	else \
		echo "Error: Input file $@.txt not found"; \
		exit 1; \
	fi

.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -rf node_modules dist

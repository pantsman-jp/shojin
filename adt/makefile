date =

.PHONY: adt run clean

# make adt date=***
adt:
	@if [ -z "$(date)" ]; then \
		echo "Usage: make adt date=***"; \
		exit 1; \
	fi
	@if [ -d "$(date)" ]; then \
		echo "$(date) already exists"; \
	else \
		rsync -a --exclude 'Makefile' template/ "$(date)"; \
		echo "$(date) created"; \
	fi

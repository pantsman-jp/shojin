date =

.PHONY: adt run clean

# make adt date=***
# create *** from atcoder/
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

CXX = g++-12

run:
	$(CXX) $(CXXFLAGS) $(word 3,$(MAKECMDGOALS)).cpp -o $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS)) && ./$(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

clean:
	rm -f $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

%:
	@:

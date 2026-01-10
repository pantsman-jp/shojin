.PHONY: solo run clean

# make solo ***
# create ahc*** from atcoder/ahc
solo:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
		echo "Usage: make solo <number>"; \
		exit 1; \
	fi
	@if [ -d "ahc$(word 2,$(MAKECMDGOALS))" ]; then \
		echo "ahc$(word 2,$(MAKECMDGOALS)) already exists"; \
	else \
		rsync -a --exclude 'Makefile' template/ "ahc$(word 2,$(MAKECMDGOALS))"; \
		echo "ahc$(word 2,$(MAKECMDGOALS)) created"; \
	fi

CXX = g++-12

# make run root-dir file-name
run:
	$(CXX) $(CXXFLAGS) $(word 3,$(MAKECMDGOALS)).cpp -o $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS)) && ./$(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

clean:
	rm -f $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

%:
	@:

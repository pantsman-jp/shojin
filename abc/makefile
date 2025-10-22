from =
to =
n =

.PHONY: range solo run clean

# make range from=* to=*
# create /abcn-to also create /abcn-to/abcn, /abcn-to/abcn+1.../abcn-to/abcm
# abc*** is copied from atcoder/abc
range:
	@if [ -z "$(from)" ] || [ -z "$(to)" ]; then \
		echo "Usage: make range from=*** to=***"; \
		exit 1; \
	fi
	@NEWFOLDER=abc$(from)-$(to); \
	if [ -d "$$NEWFOLDER" ]; then \
		echo "$$NEWFOLDER already exists"; \
	else \
		mkdir -p "$$NEWFOLDER"; \
		for i in `seq $(from) $(to)`; do \
			rsync -a --exclude 'Makefile' template/ "$$NEWFOLDER/abc$$i"; \
			echo "$$NEWFOLDER/abc$$i created"; \
		done; \
	fi

# make solo n=***
# create abc*** from atcoder/abc
solo:
	@if [ -z "$(n)" ]; then \
		echo "Usage: make solo n=***"; \
		exit 1; \
	fi
	@if [ -d "abc$(n)" ]; then \
		echo "abc$(n) already exists"; \
	else \
		rsync -a --exclude 'Makefile' template/ "abc$(n)"; \
		echo "abc$(n) created"; \
	fi

CXX = g++-12

run:
	$(CXX) $(CXXFLAGS) $(word 3,$(MAKECMDGOALS)).cpp -o $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS)) && ./$(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

clean:
	rm -f $(word 2,$(MAKECMDGOALS))/$(word 3,$(MAKECMDGOALS))

%:
	@:

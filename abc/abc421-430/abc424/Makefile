CXX = clang++
CXXFLAGS = -std=gnu++20 -O2 -Wall -Wextra

.PHONY: run clean

# make run a で a.cpp をコンパイル＆実行
run:
	$(CXX) $(CXXFLAGS) $(word 2,$(MAKECMDGOALS)).cpp -o $(word 2,$(MAKECMDGOALS)) && ./$(word 2,$(MAKECMDGOALS))

%:
	@:

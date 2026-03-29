main:
	g++ --std=c++20 -Ofast ./vector/*.cpp -o main
dev:
	g++ --std=c++20 -Og ./vector/*.cpp -o main
clean:
	rm main
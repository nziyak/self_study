# Bu makefile, lab1_nzk.c, utils.c ve utils.h dosyalarını içeren bir programı derler ve çalıştırır.

# Tüm hedefleri belirt
all: clear compile run clean

# Derleme işlemi için kural
compile: lab1_nzk.c utils_nzk.c utils_nzk.h
	@echo "Compiling..."
	@gcc lab1_nzk.c utils_nzk.c -o program

# Programı çalıştırma kuralı
run:
	@echo "Running the program...."
	./program
	@echo
	@echo "Program execution completed."

# Derleme sırasında oluşan geçici dosyaları temizleme kuralı
clean:
	@echo "Removing compiled files..."
	@rm -f program

# Ekranı temizleme kuralı
clear:
	@clear

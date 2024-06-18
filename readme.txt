== PETUNJUK ==
- Buka MSYS2 MinGW64/MinGW32 atau sejenis (Pastikan perangkat memiliki software tersebut).
- Navigasi ke direktori tempat repositori berada (cd "C/...")
- Jika ingin menjalankan program menggunakan terminal, jalankan file `main_with_terminal.c` dengan command:
  "gcc -o main_with_terminal main_with_terminal.c my_functions.c (pastikan perangkat memiliki gcc terinstal)
- Jika ingin menjalankan program menggunakan GUI, jalankan file `main_with_gui.c` dengan command:
  "gcc -o main_with_gui main_with_gui.c my_functions.c `pkg-config --cflags --libs gtk4`" (pastikan perangkat memiliki gcc dan pustaka gtk 4 terinstal)
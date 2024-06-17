#include <gtk/gtk.h>
#include "my_functions.h"

int size_data_pasien, size_riwayat_medis_pasien;
Data_Pasien *data_pasien;
Riwayat_Medis_Pasien *riwayat_medis_pasien;

typedef struct dataParam {
  GtkWidget *stack;
  GtkWidget *child;
} dataParam;

static char *copy_str(const gchar *const_str) {
  // Allocate memory for the copy
  char *modifiable_str = strdup(const_str);
  if (modifiable_str == NULL)
      // Handle memory allocation failure
      return NULL;
  return modifiable_str;
}

static void press(GtkWidget *widget, gpointer user_data) {
  dataParam *param = (dataParam*)user_data;
  gtk_stack_set_visible_child(GTK_STACK(param->stack), param->child);
}

static void informasi_kontrol_pasien(GtkButton *button, gpointer user_data) {
  GtkEntry *entry = GTK_ENTRY(user_data);
  const gchar *text = gtk_editable_get_text(GTK_EDITABLE(entry));
  const char* message = informasiKontrolPasien(riwayat_medis_pasien, size_riwayat_medis_pasien, copy_str(text));
  GtkWidget *result_label = GTK_WIDGET(g_object_get_data(G_OBJECT(button), "result_label")); // skibidi
  gtk_label_set_text(GTK_LABEL(result_label), message);
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *stack;
  GtkWidget *title;
  GtkWidget *subtitle1;
  GtkWidget *subtitle2;
  GtkWidget *subtitle3;
  GtkWidget *new_line;
  GtkWidget *grid1;
  GtkWidget *grid2;
  GtkWidget *grid3;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *button8;
  GtkWidget *button9;
  GtkWidget *button10;
  GtkWidget *button11;
  GtkWidget *button12;

  // window utama
    window = gtk_application_window_new(GTK_APPLICATION(app));
    stack = gtk_stack_new();
    gtk_window_set_child(GTK_WINDOW(window), stack);
    gtk_window_set_title(GTK_WINDOW(window), "Sistem Pencatatan Pasien Klinik X");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

  // menu utama
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_stack_add_child(GTK_STACK(stack), box);
    title = gtk_label_new("Selamat datang. Silakan pilih fitur yang telah disediakan:");
    gtk_box_append(GTK_BOX(box), title);
    subtitle1 = gtk_label_new("Manajemen Data Pasien");
    gtk_box_append(GTK_BOX(box), subtitle1);
    grid1 = gtk_grid_new();
    gtk_box_append(GTK_BOX(box), grid1);
    button1 = gtk_button_new_with_label("Tambah Data Pasien");
    gtk_grid_attach(GTK_GRID(grid1), button1, 0, 1, 1, 1);
    button2 = gtk_button_new_with_label("Ubah Data Pasien");
    gtk_grid_attach(GTK_GRID(grid1), button2, 1, 1, 1, 1);
    button3 = gtk_button_new_with_label("Cari Data Pasien");
    gtk_grid_attach(GTK_GRID(grid1), button3, 0, 0, 1, 1);
    button4 = gtk_button_new_with_label("Hapus Data Pasien");
    gtk_grid_attach(GTK_GRID(grid1), button4, 1, 0, 1, 1);
    subtitle2 = gtk_label_new("Manajemen Riwayat Medis Pasien");
    gtk_box_append(GTK_BOX(box), subtitle2);
    grid2 = gtk_grid_new();
    gtk_box_append(GTK_BOX(box), grid2);
    button5 = gtk_button_new_with_label("Tambah Riwayat Medis Pasien");
    gtk_grid_attach(GTK_GRID(grid2), button5, 0, 1, 1, 1);
    button6 = gtk_button_new_with_label("Ubah Riwayat Medis Pasien");
    gtk_grid_attach(GTK_GRID(grid2), button6, 1, 1, 1, 1);
    button7 = gtk_button_new_with_label("Cari Riwayat Medis Pasien");
    gtk_grid_attach(GTK_GRID(grid2), button7, 0, 0, 1, 1);
    button8 = gtk_button_new_with_label("Hapus Riwayat Medis Pasien");
    gtk_grid_attach(GTK_GRID(grid2), button8, 1, 0, 1, 1);
    subtitle3 = gtk_label_new("Lain-lain");
    gtk_box_append(GTK_BOX(box), subtitle3);
    grid3 = gtk_grid_new();
    gtk_box_append(GTK_BOX(box), grid3);
    button9 = gtk_button_new_with_label("Laporan Keuangan");
    gtk_grid_attach(GTK_GRID(grid3), button9, 0, 1, 1, 1);
    button10 = gtk_button_new_with_label("Analisis Pasien dan Penyakit");
    gtk_grid_attach(GTK_GRID(grid3), button10, 1, 1, 1, 1);
    button11 = gtk_button_new_with_label("Informasi Kontrol Pasien");
    gtk_grid_attach(GTK_GRID(grid3), button11, 0, 0, 2, 1);
    new_line = gtk_label_new("\n");
    gtk_box_append(GTK_BOX(box), new_line);
    button12 = gtk_button_new_with_label("Keluar");
    g_signal_connect_swapped(button12, "clicked", G_CALLBACK(gtk_window_destroy), window);
    gtk_box_append(GTK_BOX(box), button12);

    // Informasi Kontrol Pasien
      GtkWidget *box_11 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      gtk_stack_add_child(GTK_STACK(stack), box_11);
      GtkWidget *child_11 = gtk_label_new("== Informasi Kontrol Pasien ==");
      gtk_box_append(GTK_BOX(box_11), child_11);
      dataParam *param_11 = malloc(sizeof(dataParam));
      param_11->stack = stack;
      param_11->child = box_11;
      g_signal_connect(button11, "clicked", G_CALLBACK(press), (gpointer)param_11);
      GtkWidget *input_control_11= gtk_label_new("Masukkan tanggal kontrol! ");
      gtk_box_append(GTK_BOX(box_11), input_control_11);
      GtkWidget *input_11 = gtk_entry_new();
      gtk_box_append(GTK_BOX(box_11), input_11);
      GtkWidget *submit_button_11 = gtk_button_new_with_label("Submit");
      gtk_box_append(GTK_BOX(box_11), submit_button_11);
      g_signal_connect(submit_button_11, "clicked", G_CALLBACK(informasi_kontrol_pasien), input_11);
      GtkWidget *new_line_11a = gtk_label_new("\n");
      gtk_box_append(GTK_BOX(box_11), new_line_11a);
      GtkWidget *result_label_11 = gtk_label_new("");
      g_object_set_data(G_OBJECT(submit_button_11), "result_label", result_label_11); // skibidi
      gtk_box_append(GTK_BOX(box_11), result_label_11);  
      GtkWidget *new_line_11b = gtk_label_new("\n");
      gtk_box_append(GTK_BOX(box_11), new_line_11b);
      GtkWidget *back_11 = gtk_button_new_with_label("Kembali ke Menu Utama");
      gtk_box_append(GTK_BOX(box_11), back_11);
      dataParam *param_11_back = malloc(sizeof(dataParam));
      param_11_back->stack = stack;
      param_11_back->child = box;
      g_signal_connect(back_11, "clicked", G_CALLBACK(press), (gpointer)param_11_back);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;
  data_pasien = readDataPasien("Data Pasien.csv", &size_data_pasien);
  riwayat_medis_pasien = readRiwayatMedis("Riwayat Datang, Diagnosis, dan Tindakan.csv", &size_riwayat_medis_pasien);
  app = gtk_application_new("tubes.pmc", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
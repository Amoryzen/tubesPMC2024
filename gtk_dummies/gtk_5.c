#include <gtk/gtk.h>
#include "my_functions.h"

int size_data_pasien, size_riwayat_medis_pasien;
Data_Pasien *data_pasien;
Riwayat_Medis_Pasien *riwayat_medis_pasien;

typedef struct dataParam {
  GtkWidget *stack;
  GtkWidget *child;
} dataParam;

// SKIBIDI
static char *copy_str(const gchar *const_str) {
  if (const_str == NULL) {
    return NULL;
  }
  // Allocate memory for the copy
  char *modifiable_str = strdup(const_str);
  if (modifiable_str == NULL) {
    // Handle memory allocation failure
    fprintf(stderr, "Memory allocation failed for string copy\n");
    return NULL;
  }
  return modifiable_str;
}

static void press(GtkWidget *widget, gpointer user_data) {
  dataParam *param = (dataParam*)user_data;
  gtk_stack_set_visible_child(GTK_STACK(param->stack), param->child);
}

static void tambah_riwayat_medis_pasien(GtkButton *button, GtkWidget **entries) { // skibidi
  const gchar *date_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[0]));
  const gchar *id_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[1]));
  const gchar *diagnosis_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[2]));
  const gchar *action_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[3]));
  const gchar *control_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[4]));
  const gchar *bill_gchar = gtk_editable_get_text(GTK_EDITABLE(entries[5]));
  const char* message = tambahRiwayatMedisPasien(copy_str(date_gchar), copy_str(id_gchar), copy_str(diagnosis_gchar), copy_str(action_gchar), copy_str(control_gchar), 
  atof(copy_str(bill_gchar)), riwayat_medis_pasien, &size_riwayat_medis_pasien);
  tulisRiwayatMedisPasien("Riwayat Datang, Diagnosis, dan Tindakan.csv", riwayat_medis_pasien, size_riwayat_medis_pasien);
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

  // Tambah Riwayat Medis Pasien
    GtkWidget *box_5 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_stack_add_child(GTK_STACK(stack), box_5);
    GtkWidget *child_5 = gtk_label_new("== Tambah Riwayat Medis Pasien ==");
    gtk_box_append(GTK_BOX(box_5), child_5);
    dataParam *param_5 = malloc(sizeof(dataParam));
    param_5->stack = stack;
    param_5->child = box_5;
    g_signal_connect(button5, "clicked", G_CALLBACK(press), (gpointer)param_5);
    GtkWidget **entries_5 = malloc(6 * sizeof(GtkWidget*));  // skibidi
    GtkWidget *new_line_5a = gtk_label_new("\n");
    gtk_box_append(GTK_BOX(box_5), new_line_5a);    
    GtkWidget *input_name_label_5 = gtk_label_new("Masukkan tanggal! ");
    gtk_box_append(GTK_BOX(box_5), input_name_label_5);
    entries_5[0] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[0]);    
    GtkWidget *input_address_label_5 = gtk_label_new("Masukkan ID pasien! ");
    gtk_box_append(GTK_BOX(box_5), input_address_label_5);
    entries_5[1] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[1]);    
    GtkWidget *input_city_label_5 = gtk_label_new("Masukkan diagnosis! ");
    gtk_box_append(GTK_BOX(box_5), input_city_label_5);
    entries_5[2] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[2]);    
    GtkWidget *input_birthplace_label_5 = gtk_label_new("Masukkan tindakan! ");
    gtk_box_append(GTK_BOX(box_5), input_birthplace_label_5);
    entries_5[3] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[3]);    
    GtkWidget *input_birthdate_label_5 = gtk_label_new("Masukkan kontrol! ");
    gtk_box_append(GTK_BOX(box_5), input_birthdate_label_5);
    entries_5[4] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[4]);    
    GtkWidget *input_age_label_5 = gtk_label_new("Masukkan biaya (Rp)! ");
    gtk_box_append(GTK_BOX(box_5), input_age_label_5);
    entries_5[5] = gtk_entry_new();
    gtk_box_append(GTK_BOX(box_5), entries_5[5]);    
    GtkWidget *submit_button_5 = gtk_button_new_with_label("Submit");
    gtk_box_append(GTK_BOX(box_5), submit_button_5);
    g_signal_connect(submit_button_5, "clicked", G_CALLBACK(tambah_riwayat_medis_pasien), entries_5);    
    GtkWidget *new_line_5h = gtk_label_new("\n");
    gtk_box_append(GTK_BOX(box_5), new_line_5h);
    GtkWidget *result_label_5 = gtk_label_new("");
    g_object_set_data(G_OBJECT(submit_button_5), "result_label", result_label_5); // skibidi
    gtk_box_append(GTK_BOX(box_5), result_label_5);
    GtkWidget *back_5 = gtk_button_new_with_label("Kembali ke Menu Utama");
    gtk_box_append(GTK_BOX(box_5), back_5);
    dataParam *param_5_back = malloc(sizeof(dataParam)); // skibidi
    param_5_back->stack = stack;
    param_5_back->child = box;
    g_signal_connect(back_5, "clicked", G_CALLBACK(press), (gpointer)param_5_back);

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
  // Free allocated data arrays
  free(data_pasien);
  free(riwayat_medis_pasien);
  return status;
}
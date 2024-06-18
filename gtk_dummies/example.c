#include <gtk/gtk.h>

// Callback function to handle button click and display the result
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget **entries = (GtkWidget **)data;
    const gchar *entry1_text = gtk_entry_get_text(GTK_ENTRY(entries[0]));
    const gchar *entry2_text = gtk_entry_get_text(GTK_ENTRY(entries[1]));
    
    gchar *output_text = g_strdup_printf("Entry 1: %s\nEntry 2: %s", entry1_text, entry2_text);
    GtkWidget *result_label = entries[2];
    
    gtk_label_set_text(GTK_LABEL(result_label), output_text);
    g_free(output_text);
}

int main(int argc, char *argv[]) {
    // Create a new window
    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "GTK 4 Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    // Create a vertical box to arrange widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child(GTK_WINDOW(window), vbox);

    // Create entry widgets
    GtkWidget *entry1 = gtk_entry_new();
    GtkWidget *entry2 = gtk_entry_new();
    
    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Submit");
    
    // Create a label to display the result
    GtkWidget *result_label = gtk_label_new("");

    // Add widgets to the vertical box
    gtk_box_append(GTK_BOX(vbox), entry1);
    gtk_box_append(GTK_BOX(vbox), entry2);
    gtk_box_append(GTK_BOX(vbox), button);
    gtk_box_append(GTK_BOX(vbox), result_label);

    // Prepare the data to pass to the callback
    GtkWidget *entries[] = {entry1, entry2, result_label};

    // Connect the button click event to the callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entries);

    // Show all widgets
    gtk_widget_show(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

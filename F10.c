#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <gtk/gtk.h>

// Global variables

GtkWidget *window;

GtkWidget *image_view;

GtkWidget *button_take_picture;

GtkWidget *button_save_picture;

// Function declarations

void take_picture();

void save_picture();

// Main function

int main(int argc, char *argv[]) {

  // Initialize GTK

  gtk_init(&argc, &argv);

  // Create the window

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "Basic Camera");

  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  // Create the image view

  image_view = gtk_image_new();

  // Create the "Take Picture" button

  button_take_picture = gtk_button_new_with_label("Take Picture");

  g_signal_connect(button_take_picture, "clicked", G_CALLBACK(take_picture), NULL);

  // Create the "Save Picture" button

  button_save_picture = gtk_button_new_with_label("Save Picture");

  g_signal_connect(button_save_picture, "clicked", G_CALLBACK(save_picture), NULL);

  // Add the image view and buttons to the window

  gtk_container_add(GTK_CONTAINER(window), image_view);

  gtk_container_add(GTK_CONTAINER(window), button_take_picture);

  gtk_container_add(GTK_CONTAINER(window), button_save_picture);

  // Show the window

  gtk_widget_show_all(window);

  // Start the GTK main loop

  gtk_main();

  // Return success

  return 0;

}

// Function to take a picture

void take_picture() {

  // Get the current image from the image view

  GdkPixbuf *image = gtk_image_get_pixbuf(GTK_IMAGE(image_view));

  // Save the image to a file

  gchar *filename = g_strdup_printf("picture_%d.png", rand() % 1000);

  gdk_pixbuf_save(image, filename, "png");

  g_free(filename);

}

// Function to save a picture

void save_picture() {

  // Get the current image from the image view

  GdkPixbuf *image = gtk_image_get_pixbuf(GTK_IMAGE(image_view));

  // Prompt the user for a filename

  gchar *filename = gtk_file_chooser_get_filename(gtk_file_chooser_new("Save Picture", NULL, GTK_FILE_CHOOSER_ACTION_SAVE));

  // If the user canceled, return

  if (filename == NULL) {

    return;

  }

  // Save the image to the file

  gdk_pixbuf_save(image, filename, "png");

  g_free(filename);

}


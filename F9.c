#include <stdio.h>

#include <stdlib.h>

#include <gtk/gtk.h>

// Define the structure for the camera window

struct CameraWindow {

  GtkWindow *window;

  GtkWidget *image_view;

  GtkWidget *button_take_picture;

};

// Create the camera window

CameraWindow *create_camera_window() {

  CameraWindow *window = malloc(sizeof(CameraWindow));

  window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(window->window, "Camera");

  gtk_window_set_resizable(window->window, FALSE);

  // Create the image view

  window->image_view = gtk_image_new();

  gtk_container_add(GTK_CONTAINER(window->window), window->image_view);

  // Create the button to take a picture

  window->button_take_picture = gtk_button_new_with_label("Take Picture");

  g_signal_connect(window->button_take_picture, "clicked", G_CALLBACK(take_picture), window);

  gtk_container_add(GTK_CONTAINER(window->window), window->button_take_picture);

  return window;

}

// Take a picture

void take_picture(GtkWidget *widget, CameraWindow *window) {

  // Get the image from the camera

  GdkPixbuf *image = gtk_image_get_pixbuf(window->image_view);

  // Save the image to a file

  gchar *filename = g_strdup_printf("image-%d.png", rand() % 1000);

  gdk_pixbuf_save(image, filename, "png");

  g_free(filename);

  // Show a message box with the path to the image file

  GtkWidget *message_box = gtk_message_dialog_new(

      window->window, GTK_DIALOG_DESTROY_WITH_PARENT,

      GTK_MESSAGE_INFO, GTK_BUTTONS_OK,

      "The picture has been saved to the file `%s`.", filename);

  gtk_dialog_run(GTK_DIALOG(message_box));

  gtk_widget_destroy(message_box);

}

// Main function

int main(int argc, char *argv[]) {

  // Initialize GTK

  gtk_init(&argc, &argv);

  // Create the camera window

  CameraWindow *window = create_camera_window();

  // Show the window

  gtk_widget_show_all(window->window);

  // Run the GTK main loop

  gtk_main();

  // Free the camera window

  free(window);

  return 0;

}


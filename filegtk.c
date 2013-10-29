#include <gtk/gtk.h>
GtkWidget *window;
GtkWidget *entry;
void choose_file()
{
	GtkWidget* dialog;
	dialog=gtk_file_chooser_dialog_new("just choose a file",GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,
		GTK_STOCK_OPEN,GTK_RESPONSE_ACCEPT,NULL);
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_ACCEPT)
	{
		char* file=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
	    gtk_entry_set_text(GTK_ENTRY(entry),file);
	}
	gtk_widget_destroy(dialog);
}
int main( int argc, char *argv[])
{

  GtkWidget *ok;
  GtkWidget *close;

  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *halign;
  GtkWidget *valign;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  gtk_window_set_title(GTK_WINDOW(window), "fileaddition");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  vbox = gtk_vbox_new(FALSE, 5);
  entry=gtk_entry_new();
  valign = gtk_alignment_new(0, 1, 0, 0);
  gtk_container_add(GTK_CONTAINER(vbox), valign);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  hbox = gtk_hbox_new(TRUE, 3);

  ok = gtk_button_new_with_label("addfile");
  gtk_widget_set_size_request(ok, 70, 30);
  gtk_container_add(GTK_CONTAINER(hbox), ok);

  halign = gtk_alignment_new(1, 0, 0, 0);
  gtk_container_add(GTK_CONTAINER(halign), hbox);
  gtk_box_pack_start(GTK_BOX(vbox), halign, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox),entry, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(ok), "clicked",
        G_CALLBACK(choose_file), ok);
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

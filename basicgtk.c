#include <gtk/gtk.h>
enum
{
  LIST_ITEM = 0,
  N_COLUMNS
};

static void
init_list(GtkWidget *list,char* name)
{

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkListStore *store;

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes(name,
          renderer, "text", LIST_ITEM, NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

  store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);

  gtk_tree_view_set_model(GTK_TREE_VIEW(list), 
      GTK_TREE_MODEL(store));

  g_object_unref(store);
}

static void
add_to_list(GtkWidget *list, const gchar *str)
{
  GtkListStore *store;
  GtkTreeIter iter;

  store = GTK_LIST_STORE(gtk_tree_view_get_model
      (GTK_TREE_VIEW(list)));

  gtk_list_store_append(store, &iter);
  gtk_list_store_set(store, &iter, LIST_ITEM, str, -1);
}


void  on_changed(GtkWidget *widget, gpointer label) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *value;


  if (gtk_tree_selection_get_selected(
      GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, LIST_ITEM, &value,  -1);
    gtk_label_set_text(GTK_LABEL(label), value);
    g_free(value);
  }

}


int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *hbox;
  GtkWidget *artists;
  GtkWidget *albums;
  GtkWidget *songs;
GtkWidget *vbox;
GtkWidget *vbox2;
GtkWidget *vbox3;
GtkWidget *selection;
GtkWidget *label;
GtkWidget *label2;
GtkWidget *label3;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
  gtk_window_set_title(GTK_WINDOW(window), "music library");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  hbox = gtk_hbox_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), hbox);
  artists=gtk_tree_view_new();
  albums=gtk_tree_view_new();
  songs=gtk_tree_view_new();
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(artists), TRUE);
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(albums), TRUE);
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(songs), TRUE);

  gtk_box_pack_start(GTK_BOX(hbox), artists, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), albums, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), songs, TRUE, TRUE, 0);
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), artists, TRUE, TRUE, 5);
  label = gtk_label_new("");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  init_list(artists,"Artists");
  add_to_list(artists, "devisriprasad");
  add_to_list(artists, "arrehman");
  add_to_list(artists, "harrisjayraj");
  add_to_list(artists, "thamanss");
  add_to_list(artists, "mmkeeravani");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(artists));
  g_signal_connect(selection, "changed", 
      G_CALLBACK(on_changed), label);
  vbox2 = gtk_vbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox2), albums, TRUE, TRUE, 5);
  label2 = gtk_label_new("");
  gtk_label_set_justify(GTK_LABEL(label2), GTK_JUSTIFY_CENTER);
  gtk_box_pack_start(GTK_BOX(vbox2), label2, FALSE, FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), vbox2);
  init_list(albums,"Albums");
  add_to_list(albums, "Attarintiki Daredi");
  add_to_list(albums, "robo");
  add_to_list(albums, "orange");
  add_to_list(albums, "kick");
  add_to_list(albums, "magadheera");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(albums));
  g_signal_connect(selection, "changed", 
      G_CALLBACK(on_changed), label);
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));
  vbox3 = gtk_vbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox3), songs, TRUE, TRUE, 5);
  label3 = gtk_label_new("");
  gtk_label_set_justify(GTK_LABEL(label3), GTK_JUSTIFY_CENTER);
  gtk_box_pack_start(GTK_BOX(vbox3), label2, FALSE, FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), vbox3);
  init_list(songs,"Songs");
  add_to_list(songs, "Bapugaribomma");
  add_to_list(songs, "kilimanjaro");
  add_to_list(songs, "oolaoolala");
  add_to_list(songs, "goregogore");
  add_to_list(songs, "panchadharabomma");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(songs));
  g_signal_connect(selection, "changed", 
      G_CALLBACK(on_changed), label);
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

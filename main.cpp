#include <gtk/gtk.h>

static gboolean show_callback(GtkWidget *widget)
{
    g_print("Showing widget\n");
    gtk_widget_show(GTK_WIDGET(widget));
    return FALSE;
}

static gboolean hide_callback(GtkWidget *widget)
{
    g_print("Hiding widget\n");
    gtk_widget_hide(GTK_WIDGET(widget));
    return FALSE;
}

int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_move(GTK_WINDOW(window), 500, 500);
    g_timeout_add(1000, (GSourceFunc)show_callback, window);
    g_timeout_add(3000, (GSourceFunc)hide_callback, window);
    g_timeout_add(5000, (GSourceFunc)show_callback, window);

    gtk_main();
    return 0;
}

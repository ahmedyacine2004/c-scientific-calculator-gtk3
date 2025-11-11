#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

GtkWidget *entry; // Display entry

// Number buttons callback
void on_number_clicked(GtkWidget *widget, gpointer data) {
    const char *num = (const char *)data;
    const char *current = gtk_entry_get_text(GTK_ENTRY(entry));
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%s%s", current, num);
    gtk_entry_set_text(GTK_ENTRY(entry), buffer);
}

// Operator buttons callback
void on_operator_clicked(GtkWidget *widget, gpointer data) {
    const char *op = (const char *)data;
    const char *current = gtk_entry_get_text(GTK_ENTRY(entry));
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%s %s ", current, op);
    gtk_entry_set_text(GTK_ENTRY(entry), buffer);
}

// Scientific buttons callback
void on_scientific_clicked(GtkWidget *widget, gpointer data) {
    const char *func = (const char *)data;
    const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
    double val = atof(text);
    double result = 0;

    if (strcmp(func, "sin") == 0) result = sin(val);
    else if (strcmp(func, "cos") == 0) result = cos(val);
    else if (strcmp(func, "tan") == 0) result = tan(val);
    else if (strcmp(func, "log") == 0) result = log10(val);
    else if (strcmp(func, "ln") == 0) result = log(val);
    else if (strcmp(func, "sqrt") == 0) result = sqrt(val);
    else if (strcmp(func, "exp") == 0) result = exp(val);
    else if (strcmp(func, "π") == 0) result = M_PI;
    else if (strcmp(func, "e") == 0) result = M_E;

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%g", result);
    gtk_entry_set_text(GTK_ENTRY(entry), buffer);
}

// Equals button callback
void on_equals_clicked(GtkWidget *widget, gpointer data) {
    const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
    double a, b;
    char op;
    
    if (sscanf(text, "%lf %c %lf", &a, &op, &b) == 3) {
        double result = 0;
        switch(op){
            case '+': result = add(a,b); break;
            case '-': result = subtract(a,b); break;
            case '*': result = multiply(a,b); break;
            case '/': result = divide(a,b); break;
        }
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%g", result);
        gtk_entry_set_text(GTK_ENTRY(entry), buffer);
    }
}

// Clear button callback
void on_clear_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Scientific Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 720, 900); // bigger window
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Entry
    entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1.0); // Right aligned
    gtk_widget_set_size_request(entry, 600, 70);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 6, 1);

    // Scientific buttons
    const char *sci[] = {"sin", "cos", "tan", "log", "ln", "sqrt", "^", "!", "exp", "π", "e"};
    int sci_pos = 0;
    for(int row=1; row<=2; row++){
        for(int col=0; col<6; col++){
            if(sci_pos >= 11) break;
            GtkWidget *button = gtk_button_new_with_label(sci[sci_pos]);
            gtk_widget_set_size_request(button, 210, 210); // 3x bigger
            g_signal_connect(button, "clicked", G_CALLBACK(on_scientific_clicked), (gpointer)sci[sci_pos]);
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            sci_pos++;
        }
    }

    // Number buttons
    const char *numbers[] = {"7","8","9","4","5","6","1","2","3","0"};
    int pos = 0;
    for(int row=3; row<=5; row++){
        for(int col=0; col<3; col++){
            if(pos >= 9) break;
            GtkWidget *button = gtk_button_new_with_label(numbers[pos]);
            gtk_widget_set_size_request(button, 210, 210); // 3x bigger
            g_signal_connect(button, "clicked", G_CALLBACK(on_number_clicked), (gpointer)numbers[pos]);
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            pos++;
        }
    }
    // Zero button spans 2 columns
    GtkWidget *zero = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(zero, 450, 210); // 3x bigger
    g_signal_connect(zero, "clicked", G_CALLBACK(on_number_clicked), (gpointer)"0");
    gtk_grid_attach(GTK_GRID(grid), zero, 0, 6, 2, 1);

    // Operators
    const char *ops[] = {"+","-","*","/"};
    for(int i=0; i<4; i++){
        GtkWidget *button = gtk_button_new_with_label(ops[i]);
        gtk_widget_set_size_request(button, 210, 210); // 3x bigger
        g_signal_connect(button, "clicked", G_CALLBACK(on_operator_clicked), (gpointer)ops[i]);
        gtk_grid_attach(GTK_GRID(grid), button, 3, i+3, 1, 1);
    }

    // Equals
    GtkWidget *equals = gtk_button_new_with_label("=");
    gtk_widget_set_size_request(equals, 210, 210); // 3x bigger
    g_signal_connect(equals, "clicked", G_CALLBACK(on_equals_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), equals, 2, 6, 1, 1);

    // Clear
    GtkWidget *clear = gtk_button_new_with_label("C");
    gtk_widget_set_size_request(clear, 450, 210); // 3x bigger
    g_signal_connect(clear, "clicked", G_CALLBACK(on_clear_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), clear, 4, 6, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

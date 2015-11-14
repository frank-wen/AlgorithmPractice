#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 200
#define MAX_LINE 20000

typedef struct vertex node;
typedef struct Edge edge;

struct Edge {
    int label;
    node *head;
    node *tail;
};
struct vertex {
    int label;
    edge *edges[MAX];
    int edge_num;
};

node *all_nodes[MAX];
edge *all_edges[MAX_LINE];
int node_label = 1;
int edge_label = 1;

void get_numbers(int *line_numbers, char *line) {
    int i, number, ch, j;
    i = j = number = 0;
    while(line[i]) {
        ch = line[i];
        if((ch == ' ' || ch == '\t') && number != 0) {
            line_numbers[j++] = number;
            number = 0;
        }
        else 
            number = number*10 + (int)(ch-48);
        i++;
    }
    line_numbers[j] = 0;
}

void create_node(int *line_numbers) {
    int i = 0;
    int number, j;
    node *new_node = malloc(sizeof(node));
    while ((number = line_numbers[i]) != 0) {
        if (i == 0) {
            new_node->label = number;
            new_node->edge_num = 0;
            all_nodes[number-1] = new_node;
        }
        else {
            if (number < new_node->label) {
                int n = 0;
                node *this_node = all_nodes[number-1];
                while (n < this_node->edge_num) {
                    if (this_node->edges[n]->tail != NULL)
                        n++;
                    else {
                        j = new_node->edge_num++;
                        new_node->edges[j] = this_node->edges[n];
                        this_node->edges[n]->tail = new_node;
                        break;
                    }
                }
            }
            else {
                edge *new_edge = malloc(sizeof(edge));
                new_edge->label = edge_label;
                new_edge->head = new_node;
                new_edge->tail = NULL;
                j = new_node->edge_num++;
                new_node->edges[j] = new_edge;
                all_edges[edge_label-1] = new_edge;
                edge_label++;
            }
        }
        i++;
    }
    if (line_numbers[0] == 200) 
        all_edges[edge_label-1] = NULL;
}

int min_cut(node *all_nodes[],edge *all_edges[]) {
    int n = 0;
    int i;
    while (all_edges[n] != NULL) 
        n++;
    srand(time(NULL));
    i = rand()/(float)RAND_MAX *(n-1);
    printf("%d\t",i);
    node *the_node = all_node[i];
    the_edge->label = 0;


}


int main(void) {
    FILE *fp;
    int min;
    char line[MAX];
    int line_numbers[MAX];
    fp = fopen("kargerMinCut.txt","r");
    while(fgets(line, MAX, fp) != NULL) {
        get_numbers(line_numbers, line);
        create_node(line_numbers);
    }
    min = min_cut(all_nodes, all_edges);
    printf("%d\n",min);
    return 0; 
}



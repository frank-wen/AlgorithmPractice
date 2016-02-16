#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define NODE_NUM 8
#define MAX 20

int mycomp(const void *p1,const void *p2);
typedef struct Node node;
typedef struct Edge *edge;
struct Node {
    struct Edge **in_edges;
    struct Edge **out_edges;
    int label;
    int in_el;
    int out_el;
    int leader;
    bool explored;
    bool explored2;
};

struct Edge {
    node *head;
    node *tail;
};

int num2 = 0;
void DFS(node *start, node **all_nodes2, int *num) {
    int n, max;
    n = 0;
    max = start->in_el;
    start->explored = true;
    while (n < max) {
        edge edgeN = start->in_edges[n];
        if (edgeN->tail->explored == false)
            DFS(edgeN->tail,all_nodes2,num);
        n++;
    }
    all_nodes2[*num] = start;
  //  if (*num < 20 || *num > 875500)
   //     printf("%d\t",*num);
    *num = *num + 1;
}

void DFS2(node *start, int s, int *leaders, int leader_index) {
    int n, max;
    n = 0; 
    max = start->out_el;
    start->explored2 = true;
    start->leader = s;
    while (n < max) {
        edge edgeN = start->out_edges[n];
        if (edgeN->head->explored2 == false) {
            leaders[leader_index] += 1;
            DFS2(edgeN->head, s,leaders,leader_index);
        }
        n++;
    }
}

edge *append(edge *edges, int len, edge new_edge) {
    edge *new_addr;
    int base = sizeof(edge);
    if ((new_addr = malloc(len*base)) == NULL) {
        free(edges);
        exit(1);
    }
    memmove(new_addr, edges,(len-1)*base);
    new_addr[len-1] = new_edge;
    return new_addr;
}

int main(void) {
    node **all_nodes2 = malloc(sizeof(node *)*NODE_NUM);
    node *all_nodes;
    all_nodes = malloc(sizeof(node)*NODE_NUM);
    edge all_edges; 
    all_edges = malloc(sizeof(struct Edge)*MAX);
    int i = 0;
    while   (i < NODE_NUM) {
        node *temp = all_nodes+i;
        temp->label = i+1;
        temp->explored = false;
        temp->explored2 = false;
        temp->in_el = 0;
        temp->out_el = 0;
        temp->leader = 0;
        i++;
    }
    FILE *fp;
    if ((fp=fopen("test_data","r+")) == NULL)
        puts("file open error");
    int a, b,edge_label;
    edge_label = 0;
    node *head;
    node *tail;
    while (fscanf(fp,"%d %d", &b,&a) == 2) {
        int in_el, out_el;
        head = all_nodes + (a-1);
        tail = all_nodes + (b-1);
        edge new_edge;
        new_edge  = all_edges + edge_label;
        new_edge->head = head;
        new_edge->tail = tail;
        in_el = head->in_el++;
        if (in_el == 0) {
            head->in_edges = malloc(sizeof(edge));
            head->in_edges[0] = new_edge;
        }
        else 
            head->in_edges = append(head->in_edges,in_el+1,new_edge);
        out_el = tail->out_el++;
        if (out_el == 0) {
            tail->out_edges = malloc(sizeof(edge));
            tail->out_edges[0] = new_edge;
        }
        else
            tail->out_edges = append(tail->out_edges,out_el+1,new_edge);
        edge_label++;
    }
    printf("edge num: %d\n",edge_label);
    
    int index = 0;
    while(index < NODE_NUM) {
        node *temp = all_nodes + index;
        if (temp->explored == false)
          //  DFS2(temp);
            DFS(temp, all_nodes2, &num2);
        index++;
    }
    index = NODE_NUM-1;
    int leaders[1000000];
    int leader_index = 0;
    while (index > 0 && leader_index < 1000000) {
        node *temp2 = all_nodes2[index];
        if (temp2->explored2 == false) {
             int leader = temp2->label; 
             leaders[leader_index] = 1;
             DFS2(temp2,leader,leaders, leader_index);
             leader_index++;
        }
        index--;
    }
    printf("%d\t%d\n",index, leader_index);
    qsort(leaders,leader_index,sizeof(int),mycomp);
    index = 0;
    while(index < 100) 
        printf("%d\t",leaders[index++]);
    free(all_nodes);
    free(all_edges);
    free(all_nodes2);
    return 0;
}
        
int mycomp(const void *p1,const void *p2) {
    const int *n1 = (const int *)p1;
    const int *n2 = (const int *)p2;
    if (*n1 < *n2)
        return 1;
    else if (*n1 == *n2)
        return 0;
    else
        return -1;
}

/*
def DFS1(node):
    stack = list()
    first = True
    stack.append(node)
    while len(stack) > 0:
        temp = stack.pop()
        if temp.explored == False:
            temp.explored = True
            if first == False:
                all_nodes2.append(temp)
            for edge in temp.in_edges:
                if edge.tail.explored == False:
                    stack.append(edge.tail)
                    first = False

def DFS2(node,s):
    stack = list()
    stack.append(node)
    leader_num = len(leaders)
    while len(stack) > 0:
        the_node = stack.pop()
        temp = leaders[leader_num-1]
        if the_node.explored2 == False:
            the_node.explored2 = True
            leaders[leader_num-1] = (temp[0],temp[1]+1)
            node.leader = s
            for edge in the_node.out_edges:
                if edge.head.explored2 == False:
                    stack.append(edge.head)

for node in all_nodes:
    if node.explored == False:
        DFS1(node)
        all_nodes2.append(node)

leaders = list()
while(len(all_nodes2) > 0):
    node = all_nodes2.pop()
    if node.explored2 == False:
        s = node.label
        leaders.append((s,0))
        DFS2(node,s)

print('number of scc:',len(leaders))
leaders.sort(key = lambda num:num[1],reverse = True)
count = 0
for leader in leaders:
    if count < 5:
        print(leader)
        count = count+1
*/

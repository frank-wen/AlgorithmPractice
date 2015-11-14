import random
fin = open('kargerMinCut.txt')

random.seed()
class Node:
    def __init__(self,label,edges):
        self.label = label
        self.edges = edges

class Edge:
    def __init__(self, label, head, tail):
        self.label = label
        self.head = head
        self.tail = tail
all_nodes = list()
all_edges = list()

for line in fin:
    numbers = line.split()
    node = Node(int(numbers[0]),list())
    numbers = numbers[1:]
    all_nodes.append(node)
    for number in numbers:
        number = int(number)
        if number < node.label:
            temp_node = all_nodes[number-1]
            for edge_temp in temp_node.edges:
                if edge_temp.tail == None:
                    edge_temp.tail = node
                    node.edges.append(edge_temp)
                    break
        else:
            edge = Edge(len(all_edges)+1, node, None)
            node.edges.append(edge)
            all_edges.append(edge)

def min_cut(all_nodes, all_edges):
    while(len(all_nodes) > 2):
        n = random.randrange(len(all_edges))
        edge_chosed = all_edges[n]
        if random.randrange(2) != 2:
            node_a = edge_chosed.head
            node_b = edge_chosed.tail
        else:
            node_a = edge_chosed.tail
            node_b = edge_chosed.head
        for edge_a in node_a.edges:
            if edge_a in node_b.edges:
                node_b.edges.remove(edge_a)
                all_edges.remove(edge_a)
            else:
                node_b.edges.append(edge_a)
                if edge_a.head == node_a:
                    edge_a.head = node_b
                else:
                    edge_a.tail = node_b
        all_nodes.remove(node_a)

min_cut(all_nodes, all_edges)
print(len(all_nodes[0].edges), end = '\t')






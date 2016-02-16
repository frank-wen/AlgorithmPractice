class Node:
    def __init__(self,label,out_edges,in_edges,explored,explored2,leader):
        self.label = label
        self.out_edges = out_edges
        self.in_edges = in_edges
        self.explored = explored
        self.explored2 = explored2
        self.leader = leader

class Edge:
    def __init__(self,tail,head):
        self.head = head
        self.tail = tail

all_nodes = list()
all_nodes2 = list()
all_edges = list()

for i in range(8):
    all_nodes.append(Node(i+1,list(),list(),False,False,0))

fin2 = open('test_data')
for line in fin2:
    strings = line.split()
    tail_label = int(strings[0])
    head_label = int(strings[1])
    head = all_nodes[head_label-1]
    tail = all_nodes[tail_label-1]
    edge = Edge(tail,head)
    all_edges.append(edge)
    tail.out_edges.append(edge)
    head.in_edges.append(edge)


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
    print(node.label)
"""    
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
"""

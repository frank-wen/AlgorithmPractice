import heapq
fin = open('dijkstraData.txt')

class Node:
    def __init__(self,label,edges,solved,shortest,dis):
        self.label = label
        self.edges = edges
        self.solved = solved
        self.dis = dis
        self.shortest = shortest
class Edge:
    def __init__(self,head,tail,length):
        self.head = head
        self.tail = tail
        self.length = length

unsolved = list()
solved = list()
all_edges = list()
for line in fin:
    words = line.split()
    label = int(words[0])
    node = Node(label,list(),False,1000000,10000000)
    unsolved.append(node)
    pairs = words[1:]
    for pair in pairs:
        numbers = pair.split(',')
        node_label = int(numbers[0])
        length = int(numbers[1])
        if node_label > label:
            edge = Edge(node,None,length)
            node.edges.append(edge)
            all_edges.append(edge)
        else:
            head = unsolved[node_label-1]
            for edge in head.edges:
                if edge.tail == None and edge.length == length:
                    edge.tail = node
                    node.edges.append(edge)
                    break

start = unsolved[0]
start.shortest = 0
start.dis = 0
start.solved = True
solved.append(start)
unsolved.remove(start)
for edge in start.edges:
    if edge.head == start:
        edge.tail.dis = edge.length
    else:
        edge.head.dis = edge.length
unsolved.sort(key = lambda node:node.dis,reverse=True)


while len(unsolved) > 0:
    node = unsolved.pop()
#    print(node.label,node.dis,end ='\t')
    node.solved = True
    node.shortest = node.dis
    solved.append(node)
    for edge in node.edges:
        if edge.head == node:
            nodeB = edge.tail
        else:
            nodeB = edge.head
#        print('nodeB: ',nodeB.label,end='\t')
        if nodeB.solved == False:
            temp = edge.length + node.dis
#            print(temp,nodeB.dis)
            if temp < nodeB.dis:
                nodeB.dis = temp
    unsolved.sort(key = lambda node:node.dis, reverse = True)

seeked = [7,37,59,82,99,115,133,165,188,197]
ans = dict()
for node in solved:
    if node.label in seeked:
        ans[node.label] = node.shortest

for n in seeked:
    print(ans[n],end=',')

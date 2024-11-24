#BFS

graph={
'S':['B' , 'D' , 'A'],
'A':['C'],
'B':['D'],
'C':['G','D'],
'D':['G'],
}
def bfs (graph , start , goal):
    visited=[]
    queue = [[start]]
    while queue:
        path = queue.pop(0)
        node = path[-1]
        if node in visited:
            continue
        visited.append(node)
        if node == goal:
            return path
        else:
            adjacent_nodes = graph.get(node , []) 
            for node2 in adjacent_nodes:

                new_path = path.copy()
                new_path.append(node2)
                queue.append(new_path)

solution = bfs(graph,'S','G')
print('solution is', solution)

########################################################################################

#DFS
def dfs (graphh , start , goal):
        visited=[]
        stack = [[start]]
        while stack:
            path = stack.pop()
            node = path[-1]
            if node in visited:
                continue
            visited.append(node)
            if node == goal:
                return path
            else:
                adjacent_nodes = graphh.get(node , [])
                for node2 in adjacent_nodes:

                    new_path = path.copy()
                    new_path.append(node2)
                    stack.append(new_path)

solution = dfs(graph,'S','G')
print('solution is', solution)
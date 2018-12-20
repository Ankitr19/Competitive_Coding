from collections import defaultdict

class Graph:
	
	def __init__(self):
		
		self.graph = defaultdict(list)
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		
	def DFSUtil(self,v,visited,ct):
		
		visited[v] = ct
		#print (v)
		ct = ct+1
		for i in self.graph[v]:
			#print(i)
			if visited[i]==0:
				self.DFSUtil(i,visited,ct)
	
	def DFS(self,v,r,l,h):
		
		visited = [0]*(10007)
		#print(len(visited))
		ct = 1
		mx = -1
		ans = -1
		self.DFSUtil(v,visited,ct)
		for i in range(0,10007):
			if(mx<visited[i] and visited[i]!=0):
				mx = visited[i]
				ans = i
		print(ans)
			
		
	

t = int(input())
while(t>0):
	
	n = int(input())
	g = Graph()
	mini = 10009
	maxi = -1
	for i in range(0,n-1):
		a,b = input().split()
		a = int(a)
		b = int(b)
		g.addEdge(a,b)
		mini = min(a,b)
		maxi = max(a,b)
		#000000#000000
	start = int(input())
	rangei = int(maxi) - int(mini)
	
	#print(start)
	g.DFS(start,rangei,mini,maxi)
	#for i in range(mini,maxi+1):
	#	print(g.visited[i])
	#g.printGraph()
	t = t-1

import heapq

class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        # available heap: (weight, index)
        # All servers start as available at t = 0
        available = [(weight, i) for i, weight in enumerate(servers)]
        heapq.heapify(available)
        
        # busy heap: (free_time, weight, index)
        busy = []
        
        res = []
        t = 0
        
        for j, task_time in enumerate(tasks):
            # Advance time to the arrival time of the task if we are lagging behind
            t = max(t, j)
            
            # If no servers are available, jump time forward to when the earliest busy server frees up
            if not available:
                t = max(t, busy[0][0])
                
            # Release all servers that have finished their tasks by the current time t
            while busy and busy[0][0] <= t:
                free_time, weight, idx = heapq.heappop(busy)
                heapq.heappush(available, (weight, idx))
                
            # Assign the current task to the best available server
            weight, idx = heapq.heappop(available)
            res.append(idx)
            
            # Put the server into the busy heap with its new completion time
            heapq.heappush(busy, (t + task_time, weight, idx))
            
        return res

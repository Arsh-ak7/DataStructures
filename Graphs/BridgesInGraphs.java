package com.company;

import java.util.ArrayList;
import java.util.List;
import java.lang.Math.*;

import static java.lang.Math.min;

public class BridgesInGraphs {

    private int n, id;
    private int[] low, ids;
    private boolean solved;
    private boolean[] visited;
    private List<List<Integer>> graph;
    private List<Integer> bridges;

    public  BridgesInGraphs(List<List<Integer>> graph, int n){
        if(graph==null||n<=0||graph.size()!=n) throw new IllegalArgumentException();
        this.graph=graph;
        this.n=n;
    }

    public static List<List<Integer>> createGraph(int n){
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<n;i++)
            graph.add(new ArrayList<>());

        return graph;
    }

    public static void addEdge(List<List<Integer>> graph, int src, int dest){
        graph.get(src).add(dest);
        graph.get(dest).add(src);
    }

    public List<Integer> findBridges(){
        if (solved) return bridges;
        id = 0;
        low = new int[n]; // Low link values
        ids = new int[n]; // Nodes ids
        visited = new boolean[n];

        bridges = new ArrayList<>();

        // Finds all bridges in the graph across various connected components.
        for (int i = 0; i < n; i++) if (!visited[i]) dfs(i, -1, bridges);

        solved = true;
        return bridges;

    }
    private void dfs(int at, int parent, List<Integer> bridges) {

        visited[at] = true;
        low[at] = ids[at] = ++id;

        for (Integer to : graph.get(at)) {
            if (to == parent) continue;
            if (!visited[to]) {
                dfs(to, at, bridges);
                low[at] = min(low[at], low[to]);
                if (ids[at] < low[to]) {
                    bridges.add(at);
                    bridges.add(to);
                }
            } else {
                low[at] = min(low[at], ids[to]);
            }
        }
    }


    public static void main(String[] args) {
        int n=9;
        List<List<Integer>> graph = createGraph(n);
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 2);
        addEdge(graph, 1, 2);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        addEdge(graph, 2, 5);
        addEdge(graph, 5, 6);
        addEdge(graph, 6, 7);
        addEdge(graph, 7, 8);
        addEdge(graph, 8, 5);

        BridgesInGraphs solver= new BridgesInGraphs(graph,n);
        List<Integer> bridges = solver.findBridges();

        for (int i = 0; i < bridges.size() / 2; i++) {
            int node1 = bridges.get(2 * i);
            int node2 = bridges.get(2 * i + 1);
            System.out.printf("Bridge between nodes: %d and %d\n", node1, node2);
        }
    }


    }


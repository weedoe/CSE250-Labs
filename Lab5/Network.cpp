/**
 * Network.h
 *
 * OCdt Paterson 30648
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#include "Network.h"


/** This method colors all vertices in the graph WHITE. */
void Network::whiten() {
	for (int i=0 ;i<m_NetworkSize; i++){
		m_Colors[i] = WHITE;
	}
}


/** Constructs a network given a list of IP addresses
 *
 * @param IPList	Array of strings of each server's IP
 *
  */
Network::Network(const vector<string>& IPList) {
	//Debug statement
	cout << "Building a network of " << IPList.size() << " servers" << endl;
	//Fix the network size
	m_NetworkSize = IPList.size();
	//Saves the server IPs
	m_Vertex2IP = IPList;
	//Allocate space for adjacency lists and colors
	//By default there are no connections, so all nullptr
	m_EdgeLists = new EdgeListNode*[m_NetworkSize];
	for (int i=0; i<IPList.size(); i++) {
		m_EdgeLists[i] = nullptr;
	}
	m_Colors = new color[m_NetworkSize];
	//Fill a hash table for fast search using IP
	for (int i=0; i<IPList.size(); i++) {
		m_IP2Vertex.insert({IPList[i], i});
	}
	//Color the graph white
	whiten();
}

/** Frees up all allocated memory. */
Network::~Network() {
	delete[] m_EdgeLists;
	delete[] m_Colors;
}

/** Number of servers in the network */
int Network::GetNetworkSize(){
	return m_NetworkSize;
}

/** This adds a connection between two computers based on their IPs
 *  (in the adjacency edge linked list).
 *
 *  Note that it will add the edge to the adjacency list of both servers.
 *
 * @param server1	IP of the server at one end
 * @param server2	IP of the server at the other end
 */
void Network::AddConnection(const string& server1, const string& server2){
	//Extract servers index from IPs
	int v1 =  m_IP2Vertex[server1];
	int v2 =  m_IP2Vertex[server2];
	//Debug statement
	cout << "Adding edge (" << server1 << "," << server2 << ")" << endl;
	//Add the edge v1 to s2
	auto edge1 = new EdgeListNode();
	edge1->v1 = v1;
	edge1->v2 = v2;
	edge1->next = m_EdgeLists[v1];
	m_EdgeLists[v1] = edge1;
	//Add the edge v2 to v1
	//Note that since this is in the adjacency list of v2, we flip the vs
	auto edge2 = new EdgeListNode();
	edge2->v1 = v2;//see!
	edge2->v2 = v1;//so the index adjacent to v2 is v1
	edge2->next = m_EdgeLists[v2];
	m_EdgeLists[v2] = edge2;
}

/** This method must search the graph, starting on the homeServer
 * vertex, for the shortest path (in numbers of connections) to
 * the targetServer (or destination).
 *
 *   When such a path is found, it should be in the following format:
 *   homeServer,IP(1),IP(2),IP(k-1),targetServer
 *   eg: net.findShortestPath("168.213.182.122","7.9.30.185")
 *   Correct output: 168.213.182.122,83.27.248.234,7.9.30.185
 *
 * @param homeServer	IP of the starting point
 * @param targetServer	IP of the destination server
 * @return a C++ string as described above
 */

string Network::FindShortestPath(const string& homeServer, const string& targetServer) {
	//You can use a queue... for breadth first search
	queue<int> myqueue;
	//You can use a stack... if you need to ;-)
	stack<string> mystack;
	//Don't forget to whiten the graph
	whiten();
	//I suggest you first convert the IP strings back into indexes
	int home = m_IP2Vertex[homeServer];
	int destination = m_IP2Vertex[targetServer];
	//Debug statement
	cout << "Finding fastest path from  " << home << " to " << destination << endl;
    int* distances = new int[GetNetworkSize()]; //remember to delete these at the end
	int* parents = new int[GetNetworkSize()];
    for (int i=0; i<m_NetworkSize; i++) { //initialize distances and parents
        distances[i] = -1;
        parents[i] = -2;
    }
    distances[home] = 0; //initialize the home server
    myqueue.push(home); //push the home server to the queue
    while (!myqueue.empty()) {
        int current = myqueue.front(); //get the front of the queue
        myqueue.pop();
        EdgeListNode* edge = m_EdgeLists[current]; //get the edge list of the current server
        while (edge != nullptr) { //while the edge is not null
            if (m_Colors[edge->v2] == WHITE) { //if the color of the destination server is white
                m_Colors[edge->v2] = GRAY; //change the color to gray
                distances[edge->v2] = distances[current] + 1; //increment the distance
                parents[edge->v2] = current; //set the parent of the destination server to the current server
                myqueue.push(edge->v2); //push the destination server to the queue
            }
            edge = edge->next; //move to the next edge
        }
        m_Colors[current] = BLACK; //change the color of the current server to black
    }
    if (distances[destination] != -1) { //if the distance to the destination server is not -1
        int current = destination; //set the current server to the destination server
        while (current != home) { //while the current server is not the home server
            mystack.push(m_Vertex2IP[current]); //push the IP of the current server to the stack
            current = parents[current]; //set the current server to its parent
        }
        mystack.push(homeServer); //push the home server to the stack
        string path = ""; //initialize the path
        while (!mystack.empty()) { //while the stack is not empty
            path += mystack.top(); //add the top of the stack to the path
            mystack.pop(); //pop the top of the stack
            if (!mystack.empty()) { //if the stack is not empty
                path += ","; //add a comma to the path
            }
        }
        delete[] distances; //delete the distances array
        delete[] parents;
        return path;
    }
    delete[] distances; //delete the distances array
    delete[] parents;
    return "Path from " + homeServer + " to " + targetServer + " not found!";
}



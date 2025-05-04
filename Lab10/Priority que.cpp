#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class PriorityQueue {
private:
    std::vector<int> heap;
    
    // Utility functions for heap operations
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }
    
    // Maintain heap property by moving a node up in the heap
    void heapifyUp(int index) {
        // If the node is not the root and greater than its parent
        if (index > 0 && heap[index] > heap[parent(index)]) {
            // Swap with parent
            std::swap(heap[index], heap[parent(index)]);
            // Recursively heapify the parent
            heapifyUp(parent(index));
        }
    }
    
    // Maintain heap property by moving a node down in the heap
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        // If left child exists and is larger than the node
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        
        // If right child exists and is larger than the largest so far
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        
        // If the largest is not the node itself
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            // Recursively heapify the affected subtree
            heapifyDown(largest);
        }
    }
    
public:
    // Constructor
    PriorityQueue() {}
    
    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }
    
    // Get the size of the priority queue
    int size() const {
        return heap.size();
    }
    
    // Insert an element with a given priority
    void insert(int value) {
        // Add to the end of the heap
        heap.push_back(value);
        // Fix the heap property
        heapifyUp(heap.size() - 1);
    }
    
    // Extract the maximum element (highest priority)
    int deleteMax() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty!" << std::endl;
            return -1;
        }
        
        // Store the maximum value
        int maxValue = heap[0];
        
        // Replace the root with the last element
        heap[0] = heap.back();
        heap.pop_back();
        
        // Fix the heap property if there are elements left
        if (!isEmpty()) {
            heapifyDown(0);
        }
        
        return maxValue;
    }
    
    // Display all elements in the priority queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty!" << std::endl;
            return;
        }
        
        std::cout << "Priority Queue elements: ";
        for (const auto& element : heap) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    
    // Search for an element in the priority queue
    bool search(int value) const {
        for (const auto& element : heap) {
            if (element == value) {
                return true;
            }
        }
        return false;
    }
    
    // Sort the elements using heap sort
    std::vector<int> heapSort() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty!" << std::endl;
            return {};
        }
        
        // Create a copy of the heap to avoid modifying the original
        std::vector<int> sortedArray = heap;
        std::vector<int> result;
        
        // Build a max heap using the copy
        for (int i = sortedArray.size() / 2 - 1; i >= 0; i--) {
            // Heapify down each non-leaf node
            int largest = i;
            int left, right;
            
            do {
                largest = i;
                left = 2 * i + 1;
                right = 2 * i + 2;
                
                if (left < sortedArray.size() && sortedArray[left] > sortedArray[largest])
                    largest = left;
                
                if (right < sortedArray.size() && sortedArray[right] > sortedArray[largest])
                    largest = right;
                
                if (largest != i) {
                    std::swap(sortedArray[i], sortedArray[largest]);
                    i = largest;
                }
            } while (largest != i);
            
            i = (i == 0) ? -1 : i;
        }
        
        // Extract elements from the heap one by one
        int size = sortedArray.size();
        for (int i = size - 1; i > 0; i--) {
            // Move current root to end
            std::swap(sortedArray[0], sortedArray[i]);
            result.push_back(sortedArray[i]);
            
            // Call max heapify on the reduced heap
            int largest = 0;
            int left, right;
            
            do {
                largest = 0;
                left = 2 * largest + 1;
                right = 2 * largest + 2;
                
                if (left < i && sortedArray[left] > sortedArray[largest])
                    largest = left;
                
                if (right < i && sortedArray[right] > sortedArray[largest])
                    largest = right;
                
                if (largest != 0) {
                    std::swap(sortedArray[0], sortedArray[largest]);
                    largest = 0;
                }
            } while (largest != 0 && left < i);
        }
        
        result.push_back(sortedArray[0]);
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};

// Main function with menu-driven interface
int main() {
    PriorityQueue pq;
    int choice, value;
    
    do {
        std::cout << "\n----- Priority Queue ADT using Max Heap -----" << std::endl;
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Delete (Extract Max)" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Search" << std::endl;
        std::cout << "5. Sort (Heap Sort)" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: // Insert
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                pq.insert(value);
                std::cout << value << " inserted successfully." << std::endl;
                break;
                
            case 2: // Delete (Extract Max)
                if (!pq.isEmpty()) {
                    value = pq.deleteMax();
                    std::cout << "Deleted maximum element: " << value << std::endl;
                } else {
                    std::cout << "Priority Queue is empty!" << std::endl;
                }
                break;
                
            case 3: // Display
                pq.display();
                break;
                
            case 4: // Search
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (pq.search(value)) {
                    std::cout << value << " found in the Priority Queue." << std::endl;
                } else {
                    std::cout << value << " not found in the Priority Queue." << std::endl;
                }
                break;
                
            case 5: // Sort (Heap Sort)
                if (!pq.isEmpty()) {
                    std::vector<int> sorted = pq.heapSort();
                    std::cout << "Sorted elements: ";
                    for (const auto& element : sorted) {
                        std::cout << element << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "Priority Queue is empty!" << std::endl;
                }
                break;
                
            case 6: // Exit
                std::cout << "Exiting program..." << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (choice != 6);
    
    return 0;
}
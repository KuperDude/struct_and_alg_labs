t main() {
   int arr[] = { 4, 2, 2, 8, 3, 3, 1 };
   int size = sizeof(arr) / sizeof(arr[0]);

   std::cout << "Original array: ";
   for (int i = 0; i < size; ++i) {
       std::cout << arr[i] << " ";
   }
   std::cout << std::endl;

   countingSort(arr, size);

   std::cout << "Sorted array: ";
   for (int i = 0; i < size; ++i) {
       std::cout << arr[i] << " ";
   }
   std::cout << std::endl;


   int graph[MAX_NODES][MAX_NODES] = { 0 };
   int numNodes = 5;

   graph[0][1] = 1;
   graph[0][2] = 1;
   graph[1][3] = 1;
   graph[2][3] = 1;
   graph[3][4] = 1;

   std::cout << "\n\n\nBFS: ";
   bfs(graph, numNodes, 0);

   std::cout << "\nDFS: ";
   dfs(graph, numNodes, 0);

   int arr_second[] = { 1, 2, 3, 4, 5 };
   int size_second = sizeof(arr_second) / sizeof(arr_second[0]);
   int target = 4;

   int result = binarySearch(arr_second, size_second, target);
   if (result != -1) {
       std::cout << "\nBinary search: element " << target << " was found on index " << result << std::endl;
   }
   else {
       std::cout << "\nBinary search: element " << target << " was not find" << std::endl;
   }



   return 0;
}
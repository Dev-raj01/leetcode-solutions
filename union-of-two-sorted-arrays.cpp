//https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays


class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set < int > s;
        vector < int > Union;
        for (int i = 0; i < n; i++)
            s.insert(arr1[i]);
        for (int i = 0; i < m; i++)
            s.insert(arr2[i]);
        for (auto & it: s)
            Union.push_back(it);
    return Union;
        //Your code here
        //return vector with correct order of elements
    }
};
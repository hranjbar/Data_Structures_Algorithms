/*
Suppose we represent our file system as a string. For example, 
the string "user\n\tpictures\n\tdocuments\n\t\tnotes.txt" represents:

user
    pictures
    documents
        notes.txt    
The directory user contains an empty sub-directory pictures and 
a sub-directory documents containing a file notes.txt.

The string 
"user\n\tpictures\n\t\tphoto.png\n\t\tcamera\n\tdocuments\n\t\tlectures\n\t\t\tnotes.txt" 
represents:

user
    pictures
        photo.png
        camera
    documents
        lectures
            notes.txt
The directory user contains two sub-directories pictures and documents. 
pictures contains a file photo.png and an empty second-level sub-directory
camera. documents contains a second-level sub-directory lectures containing
a file notes.txt.

We want to find the longest (as determined by the number of characters) 
absolute path to a file within our system. For example, in the second 
example above, the longest absolute path is "user/documents/lectures/notes.txt", 
and its length is 33 (not including the double quotes).

Given a string representing the file system in this format, return the length 
of the longest absolute path to a file in the abstracted file system. 
If there is not a file in the file system, return 0.

Notes:

Due to system limitations, test cases use form feeds ('\f', ASCII code 12)
instead of newline characters.
File names do not contain spaces at the beginning.
Example

For fileSystem = "user\f\tpictures\f\tdocuments\f\t\tnotes.txt", the output
should be
solution(fileSystem) = 24.

The longest path is "user/documents/notes.txt", and it consists of 24 
characters.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] string fileSystem

File system in the format described above. It is guaranteed that:

the name of a file contains at least a . and an extension;
the name of a directory or sub-directory does not contain a ..
Note: Due to system limitations, newline characters are given as 
form feeds ('\f', ASCII code 12) in our test cases.

Guaranteed constraints:
1 ≤ fileSystem.length ≤ 6310.

[output] integer
*/

int solution(string fileSystem) {
    vector<string> lines;
    stringstream ss(fileSystem);
    string s;
    while(getline(ss,s,'\f')) lines.push_back(s);
    unordered_map<int, int> depth_len_map;  // {depth : length}
    depth_len_map[-1]=0;
    int ans=0;
    for (string line : lines) {
        int depth = distance(line.begin(), find_if(line.begin(), line.end(), [](char& c){return c!='\t';}));
        int file_length = line.length() - depth;
        if (find_if(line.begin(), line.end(), [](char& c){return c=='.';}) == line.end()) { // didn't find '.' and is not a file
            depth_len_map[depth] = depth_len_map[depth-1] + file_length + 1;  // +1 because of '/'
        } else {    // is a file
            ans = max(ans, depth_len_map[depth-1] + file_length);
        }
    }
    return ans;
}
/*
Approach
1. split lines of fileSystem
2. for each line, find number of prevailing tabs, this is equal to the depth of the directory or file name
3. maintain a map of lengths of each depth that will keep changing for each depth as moving down the lines
4. for each line, there are two cases:
    4.1. it's a directory: update length of current depth by adding current directory name's length to saved
            length for previous depth - don't forget the +1 for '/' character
    4.2. it's a filename: update maximum length (answer) with the length of full-path of current leaf-node file name
Note: You may wonder if over-writing depth-length map for previous directories and sub-directories affect final
answer, but it won't because we visit each file name serially and length of full-path of each file name only depends
on its immediate parent directory.
*/

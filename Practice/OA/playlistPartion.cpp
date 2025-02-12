#include <vector>
#include <algorithm>
#include <iostream>


long long getMaxPlaylists(int k, std::vector<int>& videoCategory) {
    // Sort the video categories in descending order
    std::sort(videoCategory.begin(), videoCategory.end(), std::greater<int>());
    
    long long totalPlaylists = 0;
    long long remainingVideos = 0;
    
    // Calculate total number of videos
    for (int videos : videoCategory) {
        remainingVideos += videos;
    }
    
    // Iterate until we can't form any more playlists
    while (remainingVideos >= k && videoCategory.size() >= k) {
        // Check if we can form a playlist
        if (videoCategory[k-1] > 0) {
            // Decrease the count of videos in each category
            for (int i = 0; i < k; ++i) {
                videoCategory[i]--;
                remainingVideos--;
            }
            
            // Increment the playlist count
            totalPlaylists++;

            std::sort(videoCategory.begin(), videoCategory.end(), std::greater<int>());
        
        } else {
            break;
        }
    }
    
    return totalPlaylists;
}



int main() {
    int k = 2;
    std::vector<int> vidCat = {3, 3, 3};
    
    std::cout << getMaxPlaylists(k, vidCat) << std::endl;
}
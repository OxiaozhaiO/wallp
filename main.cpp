#include <iostream>
#include <filesystem>
#include <vector>
#include <cstring>
namespace fs = std::filesystem;
std::vector<std::string> filelist;

void TraverseVideoDirectory(const std::string& rootPath) 
{
	int num = 0;
    try 
	{
        // 拼接用户根目录下的 "video" 文件夹路径
        fs::path videoPath = fs::path(rootPath) / "Video";

        // 遍历 "video" 文件夹
        for (const auto& entry : fs::directory_iterator(videoPath)) 
		{
            // 输出文件名
			std::cout<<num++<<": ";
            std::cout << entry.path().filename() << std::endl;
			filelist.push_back(entry.path().filename());

            // 如果是目录，则递归遍历
            if (fs::is_directory(entry.status())) 
			{
                TraverseVideoDirectory(entry.path());
            }
        }
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "無法查看Video目錄文件: " << e.what() << std::endl;
    }
}
void printFile()
{
    // 获取当前用户的根目录
    std::string userHome = std::getenv("HOME");
    if (!userHome.empty()) 
	{
        std::cout << "當前目錄文件:"<< std::endl;
        TraverseVideoDirectory(userHome);
    } else std::cerr << "無法打開用戶目錄." << std::endl;
}
void playVideo()
{
	char videoNum; 
	std::cout<<"输入视频编号:"; std::cin>>videoNum;
	if(videoNum == 'q') exit(0);
	char wallset[1024] = "xwinwrap -ov -fs -- mpv --no-audio -wid WID --no-osc --no-osd-bar --loop ~/Video/", *video = filelist[videoNum-'0'].data();
	strcat(wallset,video);
	system(wallset);
}
int main() 
{
	while(1)
	{
		std::cout<<"====================\n";
		printFile();
		std::cout<<"********************\n";
		playVideo();
	}
    return 0;
}


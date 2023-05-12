# mp4ToImage

这是一个用于COLMAP三维重建时，从视频分割出图片帧的GUI软件。

已知ffmpeg的基本cmd命令如下：

```cmd
1. 视频分割成jpg图片
ffmpeg.exe -i ***.mp4 %d.jpg
2. 视频分割成png图片
ffmpeg.exe -i ***.mp4 %d.png
3. jpg图片合并为mp4视频
ffmpeg.exe -f image2 -i %d.jpg ***.mp4
```

软件中下方对应的三个按钮对应了，在控制台执行相应的命令。

使用教程：

1. 选择ffmpeg程序，下载链接：[ FFMPEG Build——binaries for Windows](https://www.gyan.dev/ffmpeg/builds/)，在下载的压缩包中找到ffmpeg.exe即可
2. 选择视频文件。如果是JPG文件合并为MP4，那么视频文件的编辑框，写视频文件的保存位置+文件名。如：C://w2.mp4
3. 选择文件夹路径。如果是导出图片，那么图片为保存在该路径下；如果是合并为MP4那么，这里是图片所在的文件夹路径。


#运用python智能压缩图像
#利用glob软件包遍历指定目录，获得符合条件的全部文件路径列表；
#用PIL图像处理工具读取图像文件，检查宽度、高度，重新设定图像大小，并且存储新生成的图像；
#用os函数库检查文件或目录是否存在，创建目录，以及获取文件尺寸。

from glob import glob
from PIL import Image
import os
import math
#源路径
source_dir = 'D:/pycharm/project/test/photo'
#目标路径
target_dir = 'output'
#压缩阈值
threshold = 1*512*512
#定义压缩函数
def resize_images(source_dir, target_dir, threshold):
    filenames = glob('{}/*'.format(source_dir))                  #在指定目录下，寻找所有符合要求的文件，使用*作为通配符，查找image目录下所有文件名称
    if not os.path.exists('D:/pycharm/project/test/output'):     #用os.path.exists()函数判定目录是否存在，如果不存在，自动生成目录
        os.makedirs('D:/pycharm/project/test/output')
    #遍历所有文件
    for filename in filenames:
        filesize = os.path.getsize(filename)                     #获得文件下所有图片尺寸大小
        if filesize >= threshold:
            print(filename)
            #比较图片长、宽
            with Image.open(filename) as im:
                width, height = im.size
                #宽度大于长度
                if width >= height:
                    new_width = int(math.sqrt(threshold/2))
                    new_height = int(new_width * height * 1.0 / width)
                #长度大于宽度
                else:
                    new_height = int(math.sqrt(threshold/2))
                    new_width = int(new_height * width * 1.0 / height)
                resized_im = im.resize((new_width, new_height))
                output_filename = filename.replace(source_dir, target_dir)
                resized_im.save(output_filename)

resize_images(source_dir, target_dir, threshold)


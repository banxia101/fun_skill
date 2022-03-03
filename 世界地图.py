import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
map = Basemap(llcrnrlon=73,llcrnrlat=18,urcrnrlon=135,urcrnrlat=55,resolution='i',
              projection='merc',lat_0=42.5,lon_0=120)                         #通过经纬度确定中国区域

map.drawmapboundary(fill_color='aqua')                      #将地图涂上蓝色的一层
map.fillcontinents(color='coral')                                     #将大陆部分涂成黄色
map.drawcoastlines()
map.drawcountries()
map.readshapefile('gadm36_CHN_1','states',drawbounds=True)
plt.savefig("image_name",bbox_inches = 'tight')
plt.show()

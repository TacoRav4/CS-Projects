# Part 2
# Jason Zhang
#
# outlier Temperatures


#Input
file=input('Temperature anomaly filename:')
infile=open(file)

#Ignore the header
#Year,Value
infile.readline()

nums=[]

#Assigning variables to "null" 
maxyear=None
maxtemp=None

minyear=None
mintemp=None

#for/in loop 
for line in infile:
    line=line.strip()          #Strip off whitespace off each line end
    Year,Value=line.split(',')       #Split the variable off into individual string

    temp=float(Value)       
    year=int(Year)

    if mintemp==None or temp<mintemp:
        mintemp=temp
        minyear=Year

    if maxtemp==None or temp>maxtemp:
        maxtemp=temp
        maxyear=Year 
        
    

#Stats, these two print lines need to be out of the for/in loop 
print("Min temp:",mintemp,'in', minyear)
print("Max temp:",maxtemp,'in', maxyear)         #Print the variable to match the output format

#Closing file loop
infile.close()
 

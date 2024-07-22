# Part 1
# Jason Zhang
#
# read the temperature data 


#Input
file=input('Temperature anomaly filename:')
infile=open(file)

#Ignore the header
infile.readline()

#for loop 
for line in infile:
    line=line.strip()          #Strip off whitespace off each line end
    line=line.split(',')       #Split the variable off into individual string
    first=line[0]
    last=float(line[1])
    print(first,last)         #Print the variable to match the output format

infile.close()

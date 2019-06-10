n = int(input())
for i in range(n):
    name, studiesdate, birthdate, courses = input().split(" ")
    studiesdate = [int(x) for x in studiesdate.split("/")]
    birthdate = [int(x) for x in birthdate.split("/")]
    courses = int(courses)
    eligible = "eligible"

    if studiesdate[0] >= 2010:
        pass
    else:
        if birthdate[0] >= 1991:
            pass
        else:
            if courses > 40:
                eligible = "ineligible"
            else:
                eligible = "coach petitions"
                
    print(name + " " + eligible)

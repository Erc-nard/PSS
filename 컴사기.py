key="맛집"
result = [
    ["맛집", "광고", "빵", "맛집", "강아지"],
    ["맛집", "맛집", "학교", "맛집", "밥"],
    ["피라미드", "밥", "빵", "밥", "밥"],
    ["밥", "맛집", "맛집", "맛집", "맛집"],
    ["잠", "학교", "광고", "밥", "친구"],
    ["맛집", "맛집", "맛집", "맛집", "맛집"],
    ["광고", "밥", "맛집", "친구", "사람"]
]


ranking = {}

for i in range(7):
    if (result[i].count("광고")>0):
        continue
    count=result[i].count(key)
    ranking[count]=i
    


ranking = sorted(ranking.items(),reverse=True)

print(result[ranking[0][0]])


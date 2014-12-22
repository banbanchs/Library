#!/usr/bin/env python

import json


def main():
    with open("book.txt") as f:
        data = f.readlines()

    all_json = [json.loads(each.split('\t')[1]) for each in data]

    with open("testdata.txt", 'w') as f:
        for index, data in enumerate(all_json):
            # Need strip the space
            data['bookname'] = data['bookname'].replace(' ', '-')
            data['writer'] = data['writer'].replace(' ', '-')
            data['publisher'] = data['publisher'].replace(' ', '-')
            f.write(u"{index} {data[bookname]} {data[writer]} {data[isbn]} {data[publisher]} 3\n".format(index=index+1,
                data=data).encode('utf-8'))


if __name__ == '__main__':
    main()

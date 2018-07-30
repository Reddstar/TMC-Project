# coding=utf-8
from flask import Flask, jsonify, request
import requests
from flask_cors import CORS

app = Flask(__name__)

presence = 0
turn_on_l1 = 0
turn_on_l2 = 0
turn_on_rl = 0
turn_on_l = 0
turn_on_rac = 0
turn_on_lac = 0
turn_on_tv = 0
turn_on_wm = 0
do_open = 0


@app.route('/update', methods=['GET'])
def update_state():
    if request.method == 'GET':
        json = request.get_json()
        myquery = '{'
        myquery += '"presence" : "' + str(presence) + '", '
        myquery += '"turn_on_l1" : "' + str(turn_on_l1) + '", '
        myquery += '"turn_on_l2" : "' + str(turn_on_l2) + '", '
        myquery += '"turn_on_rl" : "' + str(turn_on_rl) + '", '
        myquery += '"turn_on_l" : "' + str(turn_on_l) + '", '
        myquery += '"turn_on_rac" : "' + str(turn_on_rac) + '", '
        myquery += '"turn_on_lac" : "' + str(turn_on_lac) + '", '
        myquery += '"turn_on_tv" : "' + str(turn_on_tv) + '", '
        myquery += '"turn_on_wm" : "' + str(turn_on_wm) + '", '
        myquery += '"do_open" : "' + str(do_open) + '"}'
        
        return str(myquery)
        

if __name__ == '__main__' :
    app.run(host="192.168.1.8")


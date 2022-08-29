function myFunction(callback){
    callback("Hau xinh gai")
}


function callback(param){
    console.log(param)
}

myFunction(callback)
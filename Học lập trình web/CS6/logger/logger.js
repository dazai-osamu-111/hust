import {
    TYPE_LOG,
TYPE_WARN,
TYPE_ERROR
} from '../constants.js'
function logger(message, type){
    console[type](message);
}

export default logger
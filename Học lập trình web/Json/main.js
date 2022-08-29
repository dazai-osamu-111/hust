var courseApi = "http://localhost:3000/course"
start()


function start(){
    getCourses(renderCourses)
    handleCreateCourse()
    
    
}

// Function

function CreateCourses(data, callback){
        var option = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
                // 'Content-Type': 'application/x-www-form-urlencoded',
              },
            body: JSON.stringify(data)
        }
        fetch(courseApi, option)
            .then(function(response){
                response.json()
            })
            .then(callback)
    }



    function handleCreateCourse(){
        var createBtn = document.querySelector('#create')
        createBtn.onclick = function(){
        var name = document.querySelector('input[name = "name"]').value
        var description = document.querySelector('input[name = "description"]').value
        var data = {
            name : name,
            description: description
        }
        CreateCourses(data, function(){
            getCourses(renderCourses)
        })
        }
    }

function getCourses(callback){
    fetch(courseApi)
        .then(function(response){
            return response.json()
        })
        .then(callback)
}

function renderCourses(courses){
    var listCourseBlock = document.querySelector("#list-courses")
    var htmls = courses.map(function(course){
        return `
        <li class = "course-item-${course.id}">
            <h4>${course.name}</h4>
            <p>${course.description}</p>
            <button onclick = deleteCourses(${course.id})>xoa</button>
        </li>
        `
    })
    listCourseBlock.innerHTML = htmls.join('')
}

function deleteCourses(id){
    var option = {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json'
            // 'Content-Type': 'application/x-www-form-urlencoded',
          },
    }
    fetch(courseApi + '/' + id, option)
        .then(function(response){
            response.json()
        })
        .then(function(response){
            var courseItem = document.querySelector('.course-item-' + id)
            courseItem.remove();
        })
}
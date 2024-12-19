const taskInput = document.getElementById('taskInput');
const addTaskButton = document.getElementById('addTaskButton');
const taskList = document.getElementById('taskList');

document.addEventListener('DOMContentLoaded', loadTasks);

addTaskButton.addEventListener('click', addTask);

function addTask() {
    const taskText = taskInput.value.trim();
    if (taskText === '') return;

    const task = {
        id: Date.now(),
        text: taskText,
        completed: false,
    };

    addTaskToDOM(task);
    saveTaskToLocalStorage(task);

    taskInput.value = '';
}

function addTaskToDOM(task) {
    const li = document.createElement('li');
    li.dataset.id = task.id;
    li.className = task.completed ? 'completed' : '';

    li.innerHTML = `
        <span>${task.text}</span>
        <div>
            <button class="complete-btn">${task.completed ? 'Oznacz jako nieukończone' : 'Ukończ'}</button>
            <button class="delete-btn">Usuń</button>
        </div>
    `;

    li.querySelector('.complete-btn').addEventListener('click', toggleTaskCompletion);
    li.querySelector('.delete-btn').addEventListener('click', deleteTask);

    taskList.appendChild(li);
}

function saveTaskToLocalStorage(task) {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.push(task);
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

function loadTasks() {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.forEach(addTaskToDOM);
}

function deleteTask(event) {
    const li = event.target.closest('li');
    const taskId = li.dataset.id;

    li.remove();
    removeTaskFromLocalStorage(taskId);
}

function removeTaskFromLocalStorage(taskId) {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    const updatedTasks = tasks.filter(task => task.id !== parseInt(taskId));
    localStorage.setItem('tasks', JSON.stringify(updatedTasks));
}

function toggleTaskCompletion(event) {
    const li = event.target.closest('li');
    const taskId = li.dataset.id;

    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    const task = tasks.find(task => task.id === parseInt(taskId));
    task.completed = !task.completed;

    localStorage.setItem('tasks', JSON.stringify(tasks));

    li.classList.toggle('completed');
    event.target.textContent = task.completed ? 'Oznacz jako nieukończone' : 'Ukończ';
}

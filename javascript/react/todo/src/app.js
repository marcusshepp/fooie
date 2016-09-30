import React from 'react';
import ReactDOM from 'react-dom';

import Header from './components/header';
import TodoList from './components/todo-list';


var todo_data = [
    {
        key: 0,
        title: "foo",
        body: "bar",
        complete: false
    },
    {
        key: 1,
        title: "mark",
        body: "shep",
        complete: true
    }
]


class Todo extends React.Component {
    constructor(){
        super();
        this.state = { todo_data };
    }
    render(){
        return(
            <div>
                <Header text={ "Todo List" } />
                <TodoList todo_data={ this.state.todo_data } />
            </div>
        );
    }
}

ReactDOM.render(<Todo />, document.getElementById('app'));

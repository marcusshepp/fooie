import React from 'react';

import TodoItem from './todo-item';


export default class TodoList extends React.Component {
    render(){
        console.log(this.props);
        return(
            <div>
                { this.props.todo_data.map(function(todo_item){
                       return <TodoItem key={ todo_item.key } item={ todo_item } />;
                }) }
            </div>
        );
    }
}

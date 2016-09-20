import React from 'react';


export default class CreateTodo extends React.Component {
    render() {
        return (
            <form onSubmit={ this.handleCreate.bind(this) }>
                <input type='text' 
                    placeholder='what to do?'
                    ref="createInput" />
                <input type='submit' value='Create' />
            </form>
        );
    }
    handleCreate(event) {
        event.preventDefault();
        this.props.createTask(this.refs.createInput.value);
        this.refs.createInput.value = '';
    }

}

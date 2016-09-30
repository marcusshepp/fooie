import React from 'react';


export default class TodoItem extends React.Component {
    render(){
        return(
            <div>
                <div>{ this.props.item.title }</div>
                <div>{ this.props.item.body }</div>
                <div>{ this.props.item.complete ? "Complete" : "Uncomplete" }</div>
                <br />
            </div>
        );
    }
}

import React from 'react';


export default class Add extends React.Component {
    handle_click(){
        this.props.add_to_count();
    }
    render(){
        return (
            <button onClick={ this.handle_click.bind(this) }>++</button>
        );
    }
}

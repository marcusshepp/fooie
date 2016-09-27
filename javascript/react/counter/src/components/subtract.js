import React from 'react';


export default class Subtract extends React.Component {
    handle_click(){
        this.props.subtract_from_count();
    }
    render(){
        return (
            <button onClick={ this.handle_click.bind(this) }>--</button>
        );
    }
}


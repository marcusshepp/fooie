import React from 'react';

import Label from './label';

export default class Input extends React.Component {
	render(){
		return(
			<div>
				{ this.props.include_label && 
					<Label
						text={ this.props.label_text }
						/> }
				<input 
					type={ this.props.type } 
					name={ this.props.name } 
					step={ this.props.step }
					/>
			</div>
		);
	}
}

